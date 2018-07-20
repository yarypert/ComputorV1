NAME = ComputorV1

SRC = ./srcs/main.c ./srcs/computor.c ./srcs/lib.c ./srcs/ft_atof.c ./srcs/simplify.c

OBJ = ./main.o ./computor.o ./lib.o ./ft_atof.o ./simplify.o

HEADER = ./

INCLUDES = -I ./includes/

all: $(NAME)

$(NAME):
	@clear
	@echo "\033[38;5;45m===ComputorV1 : Compilation...\033[0m"
	@echo "\033[38;5;45m[                              ]\033[0m"
	@gcc -c $(SRC) $(INCLUDES)
	@sleep 0.2
	@clear
	@echo "\033[38;5;45m===ComputorV1 : Compilation...\033[0m"
	@echo "\033[38;5;45m[======                        ]\033[0m"
	@gcc $(OBJ) $(INCLUDES) -o $(NAME) -lm
	@sleep 0.2
	@clear
	@echo "\033[38;5;45m===ComputorV1 : Compilation...\033[0m"
	@echo "\033[38;5;45m[============                  ]\033[0m"
	@mkdir objs
	@sleep 0.2
	@clear
	@echo "\033[38;5;45m===ComputorV1 : Compilation...\033[0m"
	@echo "\033[38;5;45m[==================            ]\033[0m"
	@mv $(OBJ) objs
	@sleep 0.2
	@clear
	@echo "\033[38;5;45m===ComputorV1 : Compilation...\033[0m"
	@echo "\033[38;5;45m[========================      ]\033[0m"
	@sleep 0.2
	@clear
	@echo "\033[38;5;45m===ComputorV1 : Compilation...\033[0m"
	@echo "\033[38;5;45m[==============================]\033[0m"
	@echo "\033[38;5;45m===ComputorV1 : Done\033[0m"


.PHONY: clean

clean :
	 @rm -Rf objs
	 @echo "\033[38;5;40m[✓] \033[38;5;15m Removed object files"

fclean: clean
	@rm -Rf $(NAME)
	@echo "\033[38;5;40m[✓] \033[38;5;15m Removed executable" $(NAME)

re : fclean all
