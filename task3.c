#include <stdio.h>
#include <stdlib.h>

int main() {
 
    const char *input_file = "bitstream1.bit";
    const char *output_file = "bitstream1.hex";

 
    FILE *file_in = fopen(input_file, "r");
	if(file_in==NULL){
        printf("Error: Could not open %s\n", input_file);
        return 1; 
    }

    
    char bits[100];
    int bit_count = 0; // Counter to keep track of the number of bits

    
    char ch;
    while ((ch = fgetc(file_in)) != EOF) { // Read until the end of the file
        if (ch == '0' || ch == '1') { // Check if the character is '0' or '1'
            bits[bit_count] = ch; 
            bit_count++; 
        }
    }
    fclose(file_in);

    // Calculate the total bits needed, rounded up to the nearest multiple of 8
    int padded_bits = bit_count;
    if (bit_count % 8 != 0) {
        padded_bits = (bit_count / 8 + 1) * 8; // Round up to next multiple of 8
    }

    // Open the output file for writing
    FILE *file_out = fopen(output_file, "w");
    if (file_out == NULL) {
        printf("Error: Could not open %s\n", output_file);
        return 1; 
    }

 
    for (int i = 0; i < padded_bits; i += 8) {
        int byte_value = 0;

        
        for (int j = 0; j < 8; j++) {
            if (i + j < bit_count && bits[i + j] == '1') {
                byte_value += (1 << j); 
            }
        }

       
        fprintf(file_out, "%02X\n", byte_value);
    }

    fclose(file_out);
    printf("Conversion complete. Output written to %s\n", output_file);

    return 0;}
