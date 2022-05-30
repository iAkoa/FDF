NAME	= fdf
HEADER	= 	include/fdf.h \
			mlx/mlx.h \
			mlx/mlx_new_window.h \
			mlx/mlx_int.h \
			mlx/mlx_opengl.h \
			mlx/mlx_png.h \
			libft129/include/gc.h \
			libft129/include/libft.h

LIBFT	= libft2

MLX		= mlx

INCLUDES= ${addprefix -I, ${sort ${dir ${HEADER}}}}

SRCS	=	main.c								\
			src/ft_parsing/ft_parsing.c			\
			src/ft_parsing/ft_ref.c				\
			src/ft_parsing/ft_free_while.c		\
			src/ft_moove/ft_zoom.c				\
			src/ft_moove/ft_translation.c		\
			src/ft_moove/ft_rotation.c			\
			src/ft_moove/ft_set.c				\
			src/ft_bresenham/ft_utils.c			\
			src/ft_bresenham/ft_bresenham.c		\
			src/ft_hook/ft_keyhook.c			\
			src/ft_hook/ft_keyhook_process.c	\
			src/ft_hook/ft_keyhook_exec.c		\
			src/ft_draw/ft_draw.c				\
			src/ft_draw/ft_draw_point.c			\
			src/ft_color/ft_color.c				\
			src/ft_color/ft_color_bresenham.c	\
			src/ft_color/ft_color_25less.c		\
			src/ft_draw/ft_my_pixel_clear.c		\
			src/ft_draw/ft_my_mlx_pixel_put.c		\

OBJS	= ${SRCS:.c=.o}
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -O2
LIBFLAGS= -framework OpenGL -framework AppKit

all: maker ${NAME}

%.o : %.c	${HEADER}
			${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

${NAME}: ${OBJS} libft2/libft2.a mlx/libmlx.a
		${CC} ${CFLAGS} ${OBJS} ${LIBFLAGS} ${INCLUDES} -o $@ libft2/libft2.a mlx/libmlx.a

maker:
		${MAKE} -C ${LIBFT}
		${MAKE}	-C ${MLX}
clean:
		rm -f ${OBJS}
		${MAKE} clean -C ${LIBFT}
		${MAKE} clean -C ${MLX}
fclean:	clean
		rm -f ${NAME}
		${MAKE} fclean -C ${LIBFT}
		${MAKE} clean -C ${MLX}
re:		fclean all
.PHONY: all clean fclean re maker
