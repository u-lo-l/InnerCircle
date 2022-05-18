#include "../INC/minishell.h"
#include <signal.h>
#include <readline/readline.h>
#include <stdio.h>
/*
 *	Ctrl+c 와 Ctrl+\ 에 해당하는 signal을 처리하는 부분이다.]
 *	- Ctrl + C : SIGINT, signo == 2
 *		명령어 입력 중, 이 인터럽트가 발생되면 현재 개행하며,
 *		입력중이던 line은 line_buffer에 남지 않는다.
 *	- Ctrl + \ : SIGQUIT, signo == 3
 *		보통의 프로세스는 sigquit 인터럽트에 의해 종료되지만
 *		쉘은 아무 것도 하지 않아야 한다.
 *		<<하지만 Ctrl+\을 누르면 ^\가 터미널에 찍힌다....>>
 *		<<arrch64환경에서만 그런거라고 믿고싶다. MAC에서의 동작 확인 필요>>
 *		->	\b 두 번 하면 ^\문자가 지워질 줄 알았는데 커서만 이동하고
 *			문자는 지워지지 않는 상황...다른 문자 2개 채워넣고 다시 \b\b하면ㄷ
 *			지워진다. 일단 임시방편으로 해결.
 *	
 *	+ 쉘 내에서 다른 프로세스가 실행중이라면..?
 *	  해당 상황에서의 시그널 처리는 추후에 고민 해 봐야겠다.
 */
void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	else if (signo == SIGQUIT)
	{
		printf("\b\b  \b\b");
	}
	return ;
}

int		set_signal_handler(void)
{
	if (signal(SIGINT, signal_handler) == SIG_ERR)
		return (FALSE);
	if (signal(SIGQUIT, signal_handler) == SIG_ERR)
		return (FALSE);
	return (TRUE);
}
