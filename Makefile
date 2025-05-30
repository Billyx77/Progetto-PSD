# Nome dell'eseguibile
TARGET = attivita

# Compilatore
CC = gcc

# Opzioni di compilazione (attiva tutti gli avvisi)
CFLAGS = -Wall -Wextra -std=c99

# File sorgente
SRCS = main.c attivita_list.c

# File oggetto (ogni .c diventa .o)
OBJS = $(SRCS:.c=.o)

# Regola principale
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Regola per creare i .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Pulizia dei file oggetto ed eseguibile
clean:
	rm -f $(OBJS) $(TARGET)
