__attribute__((sysv_abi)) void main_c() {
    // Puntero directo a la memoria de video VGA
    volatile char* video_memory = (volatile char*) 0xb8000;

    // Escribir el texto letra por letra directamente en la memoria de pantalla
    // Posición [i * 2] es la letra, posición [i * 2 + 1] es el color (0x0A = verde brillante)
    
    video_memory[0] = 'B'; video_memory[1] = 0x0A;
    video_memory[2] = 'i'; video_memory[3] = 0x0A;
    video_memory[4] = 'e'; video_memory[5] = 0x0A;
    video_memory[6] = 'n'; video_memory[7] = 0x0A;
    video_memory[8] = 'v'; video_memory[9] = 0x0A;
    video_memory[10] = 'e'; video_memory[11] = 0x0A;
    video_memory[12] = 'n'; video_memory[13] = 0x0A;
    video_memory[14] = 'i'; video_memory[15] = 0x0A;
    video_memory[16] = 'd'; video_memory[17] = 0x0A;
    video_memory[18] = 'o'; video_memory[19] = 0x0A;
    video_memory[20] = 's'; video_memory[21] = 0x0A;
    video_memory[22] = ' '; video_memory[23] = 0x0A;
    video_memory[24] = 'G'; video_memory[25] = 0x0A;
    video_memory[26] = 'r'; video_memory[27] = 0x0A;
    video_memory[28] = 'u'; video_memory[29] = 0x0A;
    video_memory[30] = 'p'; video_memory[31] = 0x0A;
    video_memory[32] = 'o'; video_memory[33] = 0x0A;
    video_memory[34] = ':'; video_memory[35] = 0x0A;
    video_memory[36] = ' '; video_memory[37] = 0x0A;
    video_memory[38] = 'J'; video_memory[39] = 0x0A;
    video_memory[40] = 'u'; video_memory[41] = 0x0A;
    video_memory[42] = 'a'; video_memory[43] = 0x0A;
    video_memory[44] = 'n'; video_memory[45] = 0x0A;
    video_memory[46] = ','; video_memory[47] = 0x0A;
    video_memory[48] = 'J'; video_memory[49] = 0x0A;
    video_memory[50] = 'o'; video_memory[51] = 0x0A;
    video_memory[52] = 's'; video_memory[53] = 0x0A;
    video_memory[54] = 'e'; video_memory[55] = 0x0A;
    video_memory[56] = ','; video_memory[57] = 0x0A;
    video_memory[58] = 'D'; video_memory[59] = 0x0A;
    video_memory[60] = 'h'; video_memory[61] = 0x0A;
    video_memory[62] = 'e'; video_memory[63] = 0x0A;
    video_memory[64] = 'i'; video_memory[65] = 0x0A;
    video_memory[66] = 'v'; video_memory[67] = 0x0A;
    video_memory[68] = 'i'; video_memory[69] = 0x0A;
    video_memory[70] = 'd'; video_memory[71] = 0x0A;
    video_memory[72] = ',', video_memory[73] = 0x0A;
    video_memory[74] = 'L'; video_memory[75] = 0x0A;
    video_memory[76] = 'u'; video_memory[77] = 0x0A;
    video_memory[78] = 'i'; video_memory[79] = 0x0A;
    video_memory[80] = 's'; video_memory[81] = 0x0A;

    // Mantener el procesador encendido sin cerrarse
    while(1);
}

