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
			iterate_funcs.c \
			main.c \
			matrix.c \
			print_debug.c \
			put_map.c \
			read_file.c \
			string_to_vectors.c
SRCS	= $(addprefix $(SRCDIR)/, $(SRCNAME))
OBJS	= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
DPS		= $(addprefix $(DPSDIR)/, $(notdir $(SRCS:.o=.d)))

.PHONY: all
all: makedir $(NAME)

-include $(DPS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -MF $(DPSDIR)/$(notdir $(<:.c=.d)) -c $< -o $@

.PHONY: makedir
makedir :
	mkdir -p $(OBJDIR)
	mkdir -p $(DPSDIR)

.PHONY: clean
clean:
	$(RM) -rf $(OBJDIR) $(DPSDIR)

.PHONY: fclean
fclean: clean
	$(RM) -f $(NAME)

.PHONY: re
re: fclean all
