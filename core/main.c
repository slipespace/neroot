// Определение констант для работы с видеопамятью
#define VIDEO_MEMORY 0xb8000
#define WHITE_ON_BLACK 0x0f
#define MAX_ROWS 25
#define MAX_COLS 80

// Функция для вывода символа на экран
void print_char(char character, int col, int row, char attribute_byte) {
    unsigned char *vidmem = (unsigned char *) VIDEO_MEMORY;
    int offset;
    
    // Вычисляем смещение
    if (col >= 0 && row >= 0) {
        offset = (row * MAX_COLS + col) * 2;
    } else {
        // Если col или row отрицательные, выводим в конец экрана
        offset = (MAX_ROWS * MAX_COLS - 1) * 2;
    }
    
    // Если character - символ перевода строки, устанавливаем курсор на новую строку
    if (character == '\n') {
        int rows = offset / (2 * MAX_COLS);
        offset = ((rows + 1) * MAX_COLS - 1) * 2;
    } else {
        // Иначе записываем символ и атрибут в видеопамять
        vidmem[offset] = character;
        vidmem[offset + 1] = attribute_byte;
    }
}

// Функция для очистки экрана
void clear_screen() {
    for (int row = 0; row < MAX_ROWS; row++) {
        for (int col = 0; col < MAX_COLS; col++) {
            print_char(' ', col, row, WHITE_ON_BLACK);
        }
    }
}

// Функция для вывода строки на экран
void print_string(char *message) {
    for (int i = 0; message[i] != '\0'; i++) {
        print_char(message[i], -1, -1, WHITE_ON_BLACK);
    }
}

// Начало выполнения программы
void _start() {
    // Очистка экрана
    clear_screen();
    
    // Вывод сообщения "Core is booting..."
    print_string("Core is booting...");
}