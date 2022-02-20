NAME	= term3d
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -MMD -MP -I $(INCDIR)

INCDIR	= ./
SRCDIR	= ./
OBJDIR	= ./obj
DPSDIR	= ./dps

SRCNAME	=	affine.c \
			convert_coordinates.c \
			count_new_line.c \
			exit_with_error.c \
			iterator.c \
			main.c \
			matrix.c \
			print_debug.c \
			putmap.c \
			read_file.c \
			string_to_vectors.c
SRCS	= $(addprefix $(SRCDIR)/, $(SRCNAME))
OBJS	= $(SRCNAME:%.c=$(OBJDIR)/%.o)
DEPS	= $(OBJS:.o=.d)

.PHONY: all
all: $(NAME)

-include $(DEPS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(RM) -rf $(OBJDIR) *.dSYM

.PHONY: fclean
fclean: clean
	$(RM) -f $(NAME)

.PHONY: re
re: fclean all
