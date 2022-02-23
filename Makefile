NAME	= term3d
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I $(INCDIR)

INCDIR	= ./include
SRCDIR	= ./src
OBJDIR	= ./obj
DPSDIR	= ./dps

SRCNAME	=	move_affine.c \
			load_count_new_line.c \
			load_exit_with_error.c \
			move_iterator.c \
			move_iterate_funcs.c \
			main.c \
			move_matrix.c \
			debug_put.c \
			draw_put_map.c \
			load_read_file.c \
			load_string_to_vectors.c \
			draw_key_event.c
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

.PHONY: test
test:
	bash test.sh
