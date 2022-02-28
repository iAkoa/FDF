NAME	= fdf
HEADER	= 	fdf.h \
			mlx/mlx.h \
			mlx/mlx_new_window.h \
			mlx/mlx_int.h \
			mlx/mlx_opengl.h \
			mlx/mlx_png.h \
			libft/libft.h

LIBFT	= Libft

MLX		= mlx

INCLUDES= ${addprefix -I, ${sort ${dir ${HEADER}}}}
SRCS	=	main.c				\
			ft_parsing.c		\
			my_mlx_pixel_put.c	\
			ft_zoom.c			\
			ft_utils.c			\
			ft_rotation.c		\
			ft_ref.c			\
			ft_bresenham.c		\
			ft_projection.c		\
			ft_set.c			\
			ft_translation.c	\
			ft_draw.c			\
			ft_keyhook.c		\
			ft_keyhook_process.c\
			ft_draw_point.c		\
			ft_color.c			\
			ft_color_bresenham.c

OBJS	= ${SRCS:.c=.o}
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
LIBFLAGS= -framework OpenGL -framework AppKit

all: maker ${NAME}

%.o : %.c	${HEADER}
			${CC} -fsanitize=address ${CFLAGS} ${INCLUDES} -c $< -o $@

${NAME}: ${OBJS} libft/libft.a mlx/libmlx.a
		${CC} -fsanitize=address ${CFLAGS} ${OBJS} ${LIBFLAGS} ${INCLUDES} -o $@ Libft/libft.a mlx/libmlx.a

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
