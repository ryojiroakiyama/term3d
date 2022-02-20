NAME	= term3d
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -MMD -MP -I $(INCDIR)

INCDIR	= ./
SRCDIR	= ./
OBJDIR	= ./obj
DPSDIR	= ./dps

SRCNAME	=	affine.c \
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
OBJS	= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
#DPS		= $(addprefix $(DPSDIR)/, $(notdir $(SRCS:.o=.d)))
DPS		= $(OBJS:.o=.d)

.PHONY: all
all: $(NAME)

-include $(DPS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(RM) -rf $(OBJDIR) $(DPSDIR)

.PHONY: fclean
fclean: clean
	$(RM) -f $(NAME)

.PHONY: re
re: fclean all
