cmake_minimum_required(VERSION 3.15)

project(open_server VERSION 1.0 LANGUAGES C)

set(TARGET_CLI "open")
set(TARGET_SERV "opend")
set(TARGET_CLI_SRC_LIST
	"cli_main.c"
	"csopen.c"
	"recv_fd.c"
	"cli_conn.c"
	)
set(TARGET_SERV_SRC_LIST
	"serv_main.c"
	"daemonize.c"
	"loop.c"
	"client.c"
	"serv_listen.c"
	"serv_accept.c"
	"handle_request.c"
	"buf_args.c"
	"cli_args.c"
	"send_err.c"
	"send_fd.c"
	"readn_writen.c"
	"log.c"
	)
set(LIBAPUE "apue")

add_executable(${TARGET_CLI} ${TARGET_CLI_SRC_LIST})
target_link_directories(${TARGET_CLI} PUBLIC "/usr/local/lib")
target_link_libraries(${TARGET_CLI} PUBLIC ${LIBAPUE})
target_include_directories(${TARGET_CLI} PUBLIC "/usr/local/include")

add_executable(${TARGET_SERV} ${TARGET_SERV_SRC_LIST})
target_link_directories(${TARGET_SERV} PUBLIC "/usr/local/lib")
target_link_libraries(${TARGET_SERV} PUBLIC ${LIBAPUE})
target_include_directories(${TARGET_SERV} PUBLIC "/usr/local/include")

install(TARGETS ${TARGET_CLI} DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})
install(TARGETS ${TARGET_SERV} DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})

