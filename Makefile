SHELL			:= /bin/sh
.SUFFIXES		:=
.SUFFIXES		:= .c .o
.DEFAULT_GOAL	:= all

CC				:= gcc
CFLAGS			:= -Wall -Wextra -Werror
CFLAGS			+= -Wpedantic -std=c11
CFLAGS			+= -Ilibft/inc -Iinc/ 
@CFLAGS			+= -I/usr/local/include/SDL2 -D_THREAD_SAFE -L/usr/local/SDL2
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

sdldir			:= sdl
sdl			:= crap.c
sdl			:= $(addprefix $(sdldir)/, $(sdl))

queuedir		:= queue
queue			:= queue.c
queue			:= $(addprefix $(queuedir)/, $(queue))

objdir			:= obj
ddir			:= dep
src				:= $(main) $(queue) $(sdl)
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
	$(CC) $(CFLAGS) -o $@ $^ -lSDL2

$(libft):
	$(MAKE) -C $(libdir)
clean:
	$(RM) $(obj) $(dep)
	$(RM) -r $(objdir) $(ddir)
	$(MAKE) -C $(libdir) clean

fclean: clean
	$(RM) -r $(NAME) $(NAME).dSYM tags
	$(MAKE) -C $(libdir) fclean

re: fclean all

run: all
	./$(NAME) 512
