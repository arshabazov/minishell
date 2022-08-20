cmake_minimum_required(VERSION 3.21)
project(minishell C)

set(CMAKE_C_STANDARD 11)

add_library(libft STATIC
        libft/ft_atoi.c
        libft/ft_bzero.c
        libft/ft_calloc.c
        libft/ft_isalnum.c
        libft/ft_isalpha.c
        libft/ft_isascii.c
        libft/ft_isdigit.c
        libft/ft_isprint.c
        libft/ft_itoa.c
        libft/ft_lstadd_back.c
        libft/ft_lstadd_front.c
        libft/ft_lstclear.c
        libft/ft_lstdelone.c
        libft/ft_lstiter.c
        libft/ft_lstlast.c
        libft/ft_lstmap.c
        libft/ft_lstnew.c
        libft/ft_lstsize.c
        libft/ft_memchr.c
        libft/ft_memcmp.c
        libft/ft_memcpy.c
        libft/ft_memmove.c
        libft/ft_memset.c
        libft/ft_putchar_fd.c
        libft/ft_putendl_fd.c
        libft/ft_putnbr_fd.c
        libft/ft_putstr_fd.c
        libft/ft_split.c
        libft/ft_strchr.c
        libft/ft_strdup.c
        libft/ft_striteri.c
        libft/ft_strjoin.c
        libft/ft_strlcat.c
        libft/ft_strlcpy.c
        libft/ft_strlen.c
        libft/ft_strmapi.c
        libft/ft_strncmp.c
        libft/ft_strnstr.c
        libft/ft_strrchr.c
        libft/ft_substr.c
        libft/ft_strtrim.c
        libft/ft_tolower.c
        libft/ft_toupper.c)

add_executable(minishell
        src/main.c
        src/minishell.h
        src/lexer/lexer.c
        src/lexer/lexer.h
        src/utils/ft_puterror.c
        src/lexer/print_list.c
        src/lexer/token_utlis.c
        src/env_var/env_var.c
        src/utils/list_ops.c
        src/parser/parser.c
        src/parser/parser.h
        src/parser/env_var_expansion.c
        src/utils/ft_substr_len.c
        src/parser/db_quotes_expansion.c src/parser/join_tokens.c src/lexer/token_value_utils.c src/parser/exit_status.c src/parser/redirect_processing.c src/parser/cmd_list_handler.c src/parser/token_list_expansion.c src/parser/token_list_eval.c src/parser/strip_spaces.c src/parser/is_redirect.c src/lexer/token_list_handler.c src/env_var/env_var_list_handler.c src/parser/str_chunk_handler.c src/parser/print_functions.c src/parser/cmd_processing.c src/parser/token_key_getter.c src/parser/clear_array.c src/utils/error_handler.c src/error.c)

target_link_libraries(minishell libft)
target_link_libraries(minishell readline)