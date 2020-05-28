## 주요 함수 prototype 및 설명 

mlx_beta/man/man3폴더 들어가셔서 강조된 제목으로 명령어 치시면 메뉴얼 페이지 볼 수 있습니다.



##### man ./mlx.3

- `void	*mlx_init ();` 



##### man ./mlx_new_window.3

- `void	*mlx_new_window ( void *mlx_ptr, int size_x, int size_y, char *title );`



##### man ./mlx_loop.3

-    `int	mlx_loop ( void *mlx_ptr );`


   ​		마지막에 이걸 쳐줘야 프로그램이 종료하지 않고 계속 돌아감

- `int	mlx_key_hook ( void *win_ptr, int (*funct_ptr)(), void *param );`

  키보드 입력받는 함수(하지만 안씀)

- `int	mlx_loop_hook ( void *mlx_ptr, int (*funct_ptr)(), void *param );`

  아무 입력이 없을때 계속 loop를 돌리는 함수.
  이 함수를 사용해서 현재 위치 정보를 기반으로 화면을 매번 새로 그려야함.

- `int mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param);`

  특이한게 man에 없음.
  모든 입력을 처리하는 함수 x_event값에 따라 key_press, key_release, mouse클릭, 창닫기버튼 등 입력을 받을 수 있음



##### man ./mlx_new_image.3

​	여기는 제 예제를 한번 보시는 것을 추천드립니다.

- `void	*mlx_new_image ( void *mlx_ptr, int width, int height );`
- `char	*mlx_get_data_addr  (  void *img_ptr, int *bits_per_pixel, int *size_line, int *endian );`
- `int	mlx_put_image_to_window ( void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y );`
- `void*	mlx_xpm_file_to_image (  void  *mlx_ptr,  char  *filename,  int  *width,  int *height );`
      

## 팁

1. 서브젝트 받을 때 mlx와 mlx_beta 두 압축파일을 주는데 beta가 개선버전인듯 한데 저는 mlx로만 사용했습니다.

   다만 mlx에는 man페이지가 없어서 mlx_beta의 man페이지를 참고했습니다.

   mlx는 이미지파일이 xpm확장자를 사용해야하는데 mlx_beta는 png도 가능한듯합니다.


2. mlx_pixel_put과 mlx_put_image_to_window는 거의 같은 기능을 합니다만
   mlx_put_image_to_window는 이미지 정보를 모았다가 한번에 그리고, mlx_pixel_put은 매번 점을 그려서 속도가 느린것 같습니다.

   따라서 mlx_put_image_to_window는 화면의 모든 pixel정보를 모았다가 한번에 그리는게 좋습니다.
   (이 이유때문인지 확실친 않지만, 두번만 써도 속도가 느려지는것을 느꼈습니다)



## 참고 사이트



- 요약: 제가 만든 예제나 1,2번으로 감을 잡고 3,4번을 통해 raycasting을 이해하면서 5번 코드를 참고해서 작성하기



1. [mlx관련 자료 모음집, 튜토리얼ft_libgfx](https://github.com/qst0/ft_libgfx)

   mlx에 대한 정보가 전체적으로 담겨있지만 처음 보기 쉽지않음

2. [Intra MinilibX강의](https://elearning.intra.42.fr/notions/minilibx/subnotions)

   처음에 mlx를 어떻게 다뤄야 하는지 시작만 알려줌
   사실 요약하면 코드 20~30줄 정도밖에 안되고 그 코드가 1번과 제 예제에 적혀있어서 안봐도 무방

3. [Raycasting Basics with JavaScript](https://courses.pikuma.com/courses/take/raycasting/lessons/7503313-player-movement)

   수학적인 개념을 모르고 raycasting을 이해할수 있게 설명해줌.
   sin, cos이 쓰이는데 그것도 설명해줌.
   다만 자바스크립트에서 쓰는 그래픽 함수가 mlx와 달라서 직접 구현해야함.
   그리고 texture를 다루는 방법은 안쓰여있고 밑에 4번과 방식이 달라서 어쩔수 없이 4번을 봐야함

4. [Raycasting explained(Lode's Computer Graphics Tutorial)](https://lodev.org/cgtutor/raycasting.html)

   cub3d를 이해하려면 4번을 거의 전부 이해해야함.
   외면하고 싶은 순간이 한둘이 아니었지만 제가 참고한 코드가 이 강의를 기반으로 하고 있어서
   어쩔수 없이 여기로 계속 되돌아왔음

5. [제가 참고한 cub3d github(42-cub3d-glagan)](https://github.com/Glagan/42-cub3d)

   제가 참고한 코드. (github에서 cub3d로 검색했을 때 star제일 많음)
   코드가 상당히 깔끔하게 짜여져있고 4번의 설명을 기반으로 하고 있어서 4번을 이해하면서 보기 좋음.
   다만 수정해야할 부분들이 존재함.(macro사용부분, --save옵션, 정사각형이 아닌 맵 등)

6. [mlx 이미지 관련 튜토리얼(images_example-keuhdall)](https://github.com/keuhdall/images_example)

   이미지를 다루기전에 한번 해보면 좋은 코드
   다만 이미지를 만드는법은 있지만
   로딩하는 법이 없었음

7. key , mouse handling관련(둘이 같은 내용)

   - [Key handle 관련](https://stackoverflow.com/c/42network/questions/164)

   - [key handle 관련 깃헙(위키)](https://github.com/VBrazhnik/FdF/wiki/How-to-handle-mouse-buttons-and-key-presses%3F)

8. 7번에서 필요한 key 코드자료
- [키코드 (이미지)](https://raw.githubusercontent.com/VBrazhnik/FdF/master/images/key_codes.png)
  
- [키코드(코드)](https://gist.github.com/jfortin42/68a1fcbf7738a1819eb4b2eef298f4f8)
  
