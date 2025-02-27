# /* ************************************************************************** */
# /*                                                     ..,,;;;,'..            */
# /*                                                 .'cx0XNNWWWNXKOdl;.        */
# /*   header_perso.c                              .;xXWNKOkkOKNMMMMMMW0l.      */
# /*                                              ,xNMXd,.   .cONMMMMMMMK;      */
# /*   Par: polaime <pthibaud>                   .:0WMX:      :XMMNNMMMMM0,     */
# /*                                             :KMMMk.      .lxdckMMMMWd.     */
# /*   Cree: 2025/01/19 13:50:28                ,OMMMMK,          ,0MMMWO'      */
# /*   Ameliore: 2025/01/19 14:42:13           .oWMMMMW0c.      .c0WMMWk,       */
# /*                                           'OMMWXNWMWKkddodkKWMMWKo.        */
# /*                                           'OMWk,,lx0XWWMMMMMWXOo'.         */
# /*   https://github.com/polaime              .oKx'    .';:clllc;'.            */
# /*                                                                            */
# /* ************************************************************************** */



#################################
## ARGUMENTS

NAME		= push_swap
CFLAGS		= -Wall -Werror -Wextra
CC			= cc

#################################
## SOURCES

SRC_FILES 	=	push_swap.c\
				push_swap_utils.c\
				ft_atoi.c\
				ft_putstr.c\
				main.c\
				push_swap_tools.c
OBJ_FILES	= $(SRC_FILES:.c=.o)

#################################
## RULES
all: presentation ${NAME}

presentation:
	@echo "__________________________________________________________________________________________________________________________________"
	@echo ""
	@echo "                                                                                      	                       ..,,;;;,'.."
	@echo "                                                                                      	                  .'cx0XNNWWWNXKOdl;."
	@echo "\033[32moooooooooo                         oooo                                                                  \033[0m.;xXWNKOkkOKNMMMMMMW0l."
	@echo "\033[32m 888    888 oooo  oooo   oooooooo8  888ooooo         oooooooo8 oooo  o  oooo ooooooo  ooooooooo\033[0m         ,xNMXd,.   .cONMMMMMMMK;"
	@echo "\033[32m 888oooo88   888   888  888ooooooo  888   888       888ooooooo  888 888 888  ooooo888  888    888\033[0m      .:0WMX:      :XMMNNMMMMM0,"
	@echo "\033[32m 888         888   888          888 888   888               888  888888888 888    888  888    888\033[0m      :KMMMk.      .lxdckMMMMWd."
	@echo "\033[32mo888o         888o88 8o 88oooooo88 o888o o888o      88oooooo88    88   88   88ooo88 8o 888ooo88\033[0m       ,OMMMMK,          ,0MMMWO'"
	@echo "\033[32m                                                                                      o888 \033[0m          .oWMMMMW0c.      .c0WMMWk,"
	@echo "                                                            		                             'OMMWXNWMWKkddodkKWMMWKo."
	@echo "\033[34m+-+-+-+ +-+-+-+-+-+-+-+-+\033[0m                   		                                 	     'OMWk,,lx0XWWMMMMMWXOo'."
	@echo "\033[34m|b|y|:| |p|t|h|i|b|a|u|d|\033[0m   				                                       	     .oKx'    .';:clllc;'."
	@echo "\033[34m+-+-+-+ +-+-+-+-+-+-+-+-+\033[0m "	
	@echo "__________________________________________________________________________________________________________________________________"
	@echo ""
	@echo ""

${NAME}: ${OBJ_FILES} 
	@echo "\033[32mCompilation en cours...\033[0m"
	@${CC} ${CFLAGS} ${OBJ_FILES} -o ${NAME} > /dev/null 2>&1
	@sleep 1
	@echo "\033[32mCompilation terminee\033[0m"

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@ > /dev/null 2>&1

clean: presentation
	@rm -f ${OBJ_FILES}
	@echo "\033[31mFichiers objets supprimés.\033[0m"

fclean: clean
	@rm -f ${NAME}
	@echo "\033[31mExecutable supprimé.\033[0m"

re: fclean all
.PHONY: all clean fclean re presentation