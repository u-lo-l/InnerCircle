#include "../INC/minishell.h"
#include <stdlib.h>

/*
 *	미니쉘이 실행되고 쉘 변수를 초기화 하는 부분이다.
 *	이 부분에서 빌트인 또한 초기화 될 것이다. (MAYBE)
 *	시그널 핸들러 처리도 여기 넣을 수 있다.
*/
int init_shell(int argc, char **argv, char **envp)
{
	if (argc > 1 || argv[1] != NULL || envp == NULL)
		return (FALSE);
	return (TRUE);
}

/*
 *	작은 쉘을 구현하는 부분이다.
 *	필요 기능 : 
 *		Ctrl-C Ctrl-\ 에 해당하는 시그널 처리 (signal)
 *			Ctrl-C와 Ctrl-\는 각각 SIGINT(2), SIGQUIT(3)이고,
 *			이 때의 signal handeler만 작성하면 된다.
 *		이 프로그램 만의 환경 변수를 따로 가지고 있어야한다. (export unset env에서 쓰인다.)
 *			main 함수의 3번째 전달인자로 envp를 받으면 이를 가지고 list(dictionary)를 만든다.
 *			각 노드는 NAME, VALUE, next_node_ptr을 멤버로 갖는다.
 *		prompt를 출력한 상태로 명령어 입력을 기다리며, 작업 히스토리를 갖는다.(readline)
 *		Ctrl-D만 입력된 경우 종료 (realine)
 *		쉘 환경 변수에 대한 word expansion
 *		큰 따옴표와 작은 따옴표에 대한 quote removal
 *		각종 built-in들을 직접 구현 (echo [-n], cd, pwd, export, unset, env, exit)
 *		실행 가능한 실행파일 실행(상대 혹은 절대 경로 모두 작동해야함)
 *		리다이렉션 (> >> < <<)
 *		표준 입출력 파이프 (|)
 *	제한된 기능 :
 *		명시 되지 않은 특수문자에 대한 구현 (Mandatory에 명시된 special character : $)
 *		닫히지 않은 따옴표에 대한 해석
 *		하나를 초과하는 전역변수의 사용
*/
int main(int argc, char **argv, char **envp)
{
	char *command_line;
	
	if (init_shell(argc, argv, envp) == FALSE)
		return (1);
	while (1)
	{
		command_line = read_command("vv MINISHELL vv\n> ");
		free(command_line);
	}
	return (0);
}