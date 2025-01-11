//O(n2)
for (i = 0; i <= n - m; i++) {  // Loop through the text, ensuring there's enough room for the pattern
    c = 0;                      // Reset the match counter
    for (j = 0; j < m; j++) {   // Loop through the pattern
        if (a[i + j] != a[j]) { // Mismatch check
            i++;                // Move to the next starting index in the text
            break;              // Exit inner loop
        } else {
            c++;                // Increment match counter
        }
    }
    if (c == m) {               // If full pattern is matched
        return i;               // Return the starting index
    }
}
return -1;                      // Return -1 if no match is found
