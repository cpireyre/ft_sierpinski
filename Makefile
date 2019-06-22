SHELL			:= /bin/sh
.SUFFIXES		:=
.SUFFIXES		:= .c .o
.DEFAULT_GOAL	:= all

CC				:= gcc
CFLAGS			:= -Wall -Wextra -Werror
CFLAGS			+= -Wpedantic -std=c11
CFLAGS			+= -Ilibft/inc -Iinc/
DEBUG			:= -g3
CFLAGS			+= $(DEBUG)
NAME			:= sierpinski

VPATH			:= src

libdir			:= libft
lib				:= libft.a
libft			:= $(addprefix $(libdir)/, $(lib))

maindir			:= main
main			:= sierpinski.c main.c
main			:= $(addprefix $(maindir)/, $(main))

queuedir		:= queue
queue			:= queue.c
queue			:= $(addprefix $(queuedir)/, $(queue))

objdir			:= obj
ddir			:= dep
src				:= $(main) $(queue)
obj				:= $(addprefix $(objdir)/, $(src:%.c=%.o))
dep				:= $(addprefix $(ddir)/, $(src:%.c=%.d))

-include $(dep)

%/.f:
	mkdir -p $(@D)
	touch $@

.PRECIOUS: %/.f
.SECONDEXPANSION:
.PRECIOUS: $(obj)

dname = $(subst $(1),$(2),$(basename $(3))).d
$(objdir)/%.o:	%.c $$(@D)/.f $$(subst $(objdir),$(ddir),$$(@D))/.f
	$(CC) $(CFLAGS) -c $< -o $@ -MMD -MP -MF $(call dname,$(objdir),$(ddir),$@)

.PHONY: all
all: $(NAME)

$(NAME): $(obj) $(libft)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(obj) $(dep)
	$(RM) -r $(objdir) $(ddir)

fclean: clean
	$(RM) -r $(NAME) $(NAME).dSYM tags

re: fclean all

run: all
	./$(NAME) 10
