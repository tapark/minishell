# minishell

입력받는 인자들
1. 명령어 (echo, cd 등)
2. 옵션 (-n 등)
3. 파이프라인 (|)
4. 리다이렉션 (<, >, >>)
5. 명령어(1)와 옵션(2)을 감싸는 따옴표('')/쌍따옴표("")

예외로 생각해볼 수 있는 사항(구현x)
1. 따옴표나 쌍따옴표가 홀수개로 들어가는 경우 echo "hello""
2. escape문자(\)의 기능들

인자 파싱 아이디어(?)
1. 연결리스트(예시)
~~~C
typedef struct s_input
{
  char *token;
  int qt;
  int dqt;
  int pipe;
  int re;
  int dre;
  sturct s_input *next;
} t_input;
~~~
