#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdint.h>


typedef struct ITUColorStr {

    int alpha;
    int red;
    int green;
    int blue;

} ITUColor;

static unsigned char gray_color[32][32] = {   {255, 255, 255, 255},
                                            {255, 40, 224, 138},
                                            {25, 30, 238, 100},
                                            {25, 20, 192, 145}
                                        };

static ITUColor color[32][32];
static float red[32][32];
static float green[32][32];
static float blue[32][32];
static float gaussian_kernel[3][3];
static pthread_t init_gaussian_tid;
static pthread_t run_gaussian_tid;




#define GAUSSIAN_KERNEL_SIZE            (3)
#define GAUSSIAN_KERNEL_HALF_SIZE       (GAUSSIAN_KERNEL_SIZE>>1)
#define IMAGE_WIDTH                     (32)
#define IMAGE_HEIGHT                    (32)
#define EXTEND_IMAGE_WIDTH              (IMAGE_WIDTH+GAUSSIAN_KERNEL_HALF_SIZE*2)
#define EXTEND_IMAGE_HEIGHT             (IMAGE_HEIGHT+GAUSSIAN_KERNEL_HALF_SIZE*2)

void getGaussianKernel(float kernel[GAUSSIAN_KERNEL_SIZE][GAUSSIAN_KERNEL_SIZE], const float sigma)
{
    float sum = 0.0f;
    const float sigma_2 = sigma*sigma;
    const float a = 1.0 / (2 * 3.14159*sigma_2);

    for (int i = 0; i < GAUSSIAN_KERNEL_SIZE; ++i)
    {
        float dy = i - GAUSSIAN_KERNEL_HALF_SIZE;

        for (int j = 0; j < GAUSSIAN_KERNEL_SIZE; ++j)
        {
            float dx = j - GAUSSIAN_KERNEL_HALF_SIZE;

            kernel[i][j] = a*exp(-((dx*dx + dy*dy) / (2.0*sigma_2)));

            sum += kernel[i][j];
        }
    }

    if (sum != 0) {

        sum = 1.0 / sum;
        for (int i = 0; i < GAUSSIAN_KERNEL_SIZE; ++i)
            for (int j = 0; j < GAUSSIAN_KERNEL_SIZE; ++j)
                kernel[i][j] *= sum;
    }

}

void getRGBColor(ITUColor *color, uint8_t gray_value)
{
	static uint8_t red, green, blue;
    static double temp = 0.0;
	
	if (gray_value >= 0 && gray_value <= 51)
	{
		red = 0;
		green = gray_value*5;
		blue = 255;
	}
	else if (gray_value >= 52 && gray_value <= 102)
	{
		red = 0;
		green = 255;
		blue = 255-(gray_value-51)*5;
	}
	else if (gray_value >= 103 && gray_value <= 153)
	{
		red = (gray_value-102)*5;
		green = 255;
		blue = 0;
	}
	else if (gray_value >= 154 && gray_value <= 204)
	{
		red = 255;
		temp = round(255-128*(gray_value-153)/51.0);
		green = (uint8_t) temp;
		blue = 0;
	}
    else
	{
		red = 255;
		temp = round(127-127*(gray_value-204)/51.0);
		green = (uint8_t) temp;
		blue = 0;
	}

	color->alpha = 255;
	color->red = red;
	color->green = green;
	color->blue = blue;
}

void setRGBColor(ITUColor color[IMAGE_WIDTH][IMAGE_HEIGHT],
                float red[IMAGE_WIDTH][IMAGE_HEIGHT], 
                float green[IMAGE_WIDTH][IMAGE_HEIGHT],
                float blue[IMAGE_WIDTH][IMAGE_HEIGHT])
{

    for (int h = 0; h < IMAGE_WIDTH; ++h) {
        for (int w = 0; w < IMAGE_HEIGHT; ++w) {
			red[h][w] = color[h][w].red/1.0;
			green[h][w] = color[h][w].green/1.0;
			blue[h][w] = color[h][w].blue/1.0;
        }
    }
}


void FliterFill(float dst_arr[EXTEND_IMAGE_WIDTH*EXTEND_IMAGE_HEIGHT], float src_arr[IMAGE_WIDTH*IMAGE_HEIGHT])
{

    int width = IMAGE_WIDTH, height = IMAGE_HEIGHT, 
                half_filter_width = GAUSSIAN_KERNEL_HALF_SIZE, 
                half_filter_height = GAUSSIAN_KERNEL_HALF_SIZE;
    float *dst = &dst_arr[0];
    float *src = &src_arr[0];

    //中间重叠部分
    for(int i = 0; i < height; i++)
    {
        memcpy(dst + ((width + 2 * half_filter_height) *(i+half_filter_height) + half_filter_height), src + width * i, width * sizeof(float));
    }
    //左侧
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < half_filter_width; j++)
        {
            dst[(width + 2 * half_filter_height)*(i + half_filter_width) + j] = src[width * i];
        }
    }
    //右侧
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < half_filter_width; j++)
        {
            dst[(width + 2 * half_filter_height)*(i + half_filter_width + 1) - 1 - j] = src[width*(i + 1) - 1];
        }
    }
 
    //前half_filter_height行
    for (int i = 0; i < half_filter_height; i++)
    {
        memcpy(dst + i * (width + 2 * half_filter_width), dst + half_filter_height * (width + 2 * half_filter_width), (width + 2 * half_filter_width) * sizeof(float));
    }
 
    //后half_filter_height行
    for (int i = 0; i < half_filter_height; i++)
        memcpy(dst + (width + 2 * half_filter_width)*(height + half_filter_height + i), dst + ((width + 2 * half_filter_width)*(height - 1 + half_filter_height)), (width + 2 * half_filter_width) * sizeof(float));

}



void gaussianFilter(float color[IMAGE_WIDTH][IMAGE_HEIGHT], float filter[GAUSSIAN_KERNEL_SIZE][GAUSSIAN_KERNEL_SIZE])
{
	float newColor[EXTEND_IMAGE_WIDTH][EXTEND_IMAGE_HEIGHT] = {0};

    float *color_row, *newColor_row_width_offset;

	FliterFill((float *)newColor, (float *)color);
    float sum = 0.0;

    printf("(0,0)%f (0,1)%f (1,1)%f\n", newColor[0][0], newColor[0][1], newColor[1][1]);

    for (int i = GAUSSIAN_KERNEL_HALF_SIZE; i < (EXTEND_IMAGE_HEIGHT - GAUSSIAN_KERNEL_HALF_SIZE); ++i) {

        color_row = &color[i - GAUSSIAN_KERNEL_HALF_SIZE][0];

        for (int j = GAUSSIAN_KERNEL_HALF_SIZE ; j < (EXTEND_IMAGE_WIDTH - GAUSSIAN_KERNEL_HALF_SIZE); ++j) {

            sum = 0.0;

            for (int y = 0 ; y < GAUSSIAN_KERNEL_SIZE; ++y) {

                newColor_row_width_offset = &newColor[i-GAUSSIAN_KERNEL_HALF_SIZE][y];

                for (int x = 0 ; x < GAUSSIAN_KERNEL_SIZE; ++x) {

                    sum += newColor_row_width_offset[j - GAUSSIAN_KERNEL_HALF_SIZE + x] * filter[y][x];
                    
                }
            }
            color_row[j - GAUSSIAN_KERNEL_HALF_SIZE] = sum;
        }
    }
}


void saveRGBColor(ITUColor color[IMAGE_WIDTH][IMAGE_HEIGHT],
                float red[IMAGE_WIDTH][IMAGE_HEIGHT], 
                float green[IMAGE_WIDTH][IMAGE_HEIGHT],
                float blue[IMAGE_WIDTH][IMAGE_HEIGHT])
{
    for (int y = 0; y < IMAGE_HEIGHT; y++) {
        for (int x = 0; x < IMAGE_WIDTH; x++) {
            color[y][x].alpha = 255;
			color[y][x].red = (int)red[y][x];
			color[y][x].green = (int)green[y][x];
			color[y][x].blue = (int)blue[y][x];
        }
    }
}


static void *init_gaussian_task(void *arg) {

    getGaussianKernel(gaussian_kernel, 1.5f);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)
            printf("%f ", gaussian_kernel[i][j]);
        putchar('\n');
    }

    return NULL;
}

static void *run_gaussian_task(void *arg) {

    for (uint8_t row = 0; row < 32; ++row)
        for (uint8_t col = 0; col < 32; ++col)
            getRGBColor(&color[row][col], gray_color[row][col]);    
    printf("color[0][1] RGB: %d %d %d\n", color[0][0].red, color[0][0].green, color[0][0].blue);

    setRGBColor(color, red, green, blue);
    printf("color[0][1] RGB: %f %f %f\n", red[0][0], green[0][0], blue[0][0]);

    gaussianFilter(red, gaussian_kernel);
    gaussianFilter(green, gaussian_kernel);
    gaussianFilter(blue, gaussian_kernel);
    printf("color[0][0] RGB: %f %f %f\n", red[0][0], green[0][0], blue[0][0]);

    saveRGBColor(color, red, green, blue);
    printf("color[31][31] RGB: %d %d %d\n", color[31][31].red, color[31][31].green, color[31][31].blue);

    return NULL;
}


int main(void) {



    pthread_create(&init_gaussian_tid, NULL, init_gaussian_task, NULL);
    pthread_join(init_gaussian_tid, NULL);

    pthread_create(&run_gaussian_tid, NULL, run_gaussian_task, NULL);
    pthread_join(run_gaussian_tid, NULL);


    return 0;
}