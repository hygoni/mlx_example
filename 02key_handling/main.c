#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>

#define X_EVENT_KEY_PRESS	2
#define KEY_MASK		(1L << 0)

#define KEY_W			119
#define KEY_A			97
#define KEY_S			115
#define KEY_D			100
#define KEY_ESC 		65307
#define KEY_Q 			113
#define KEY_R 			114
#define KEY_LEFT_ARROW		65361
#define KEY_UP_ARROW		65362
#define KEY_RIGHT_ARROW		65363
#define KEY_DOWN_ARROW		65364

 //밑에 key_press()에 넘겨줄 변수들, 인자를 하나만 받기때문에 structure로 한곳에 모아야함
 //x,y, str은 임의로 만든 변수들
typedef struct s_param{
	int		x;
	int		y;
	char	str[3];
}				t_param;

void			param_init(t_param *param)
{
	param->x = 3;
	param->y = 4;
	param->str[0] = 'a';
	param->str[1] = 'b';
	param->str[2] = '\0';
}

int				key_press(int keycode, t_param *param)
{
	if (keycode == KEY_W)//W 눌렸을때 동작할 내용
		printf("str:%s\n", param->str);
	else if (keycode == KEY_A) //A가 눌렸을 때
		printf("location: x=%d, y=%d\n", param->x, param->y);
	else if (keycode == KEY_ESC) //ESC가 눌렸을 때 종료하기
		exit(0);
	else
	{
		printf("you entered is %d\n", keycode);
		printf("'W' key: Print string\n");
		printf("'A' key: Print location\n");
		printf("'ESC' key: Exit this program\n");
	}
	return (0);
}

int			main(void)
{
	void		*mlx;
	void		*win;
	t_param		param;

	param_init(&param);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "mlx_project");
	mlx_hook(win, X_EVENT_KEY_PRESS, KEY_MASK, &key_press, &param);
	mlx_loop(mlx);
}
