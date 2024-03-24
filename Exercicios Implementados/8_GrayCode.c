 // parameters: value, base, digits
 // Convert a value to a graycode with the given base and digits. Iteratingmake ete

 // through a sequence of values would result in a sequence of graycodes in
 // which only one digit changes at a time.

 int baseN[digits];  // Stores the ordinary base-N number, one digit per entry
 int gray[digits];   // Stores the base-N graycode number
 int i;              // The loop variable

 // Put the normal baseN number into the baseN array. For base 10, 109
 // would be stored as [9,0,1]
 int tempvalue = value;
 for(i = 0; i < digits; i++) {
        baseN[i] = tempvalue % base;
        tempvalue /= base;
 }

 // Convert the normal baseN number into the graycode equivalent. Note that
 // the loop starts at the most significant digit and goes down.
 int shift = 0;
 for(i = digits - 1; i >= 0; i--) {
        // The gray digit gets shifted down equal to the sum of the higher
        // digits.
        gray[i] = (baseN[i] - shift) % base;
        shift += gray[i] - base;  // - base to prevent negative in mod operation
 }
 // EXAMPLES
 // input: value = 1899, base = 10, digits = 4
 // output: baseN[] = [9,9,8,1], gray[] = [0,1,7,1]
 // input: value = 1900, base = 10, digits = 4
 // output: baseN[] = [0,0,9,1], gray[] = [0,1,8,1]
