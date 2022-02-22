NAME	= term3d
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I $(INCDIR)

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
DPS		= $(addprefix $(DPSDIR)/, $(notdir $(SRCS:.c=.d)))

.PHONY: all
all: $(OBJDIR) $(DPSDIR) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS)  -MMD -MP -MF $(DPSDIR)/$(notdir $(<:.c=.d)) -c $< -o $@

-include $(DPS)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(DPSDIR):
	mkdir -p $(DPSDIR)

.PHONY: clean
clean:
	$(RM) -rf $(OBJDIR) $(DPSDIR)

.PHONY: fclean
fclean: clean
	$(RM) -f $(NAME)

.PHONY: re
re: fclean all
