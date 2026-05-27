// sluice-bench-1.c – Pattern matching filter for sluice gate
// Compile: gcc sluice-bench-1.c -o sluice1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// is_ripe – pattern matching logic (returns 1 if candidate passes)
int is_ripe(const char *line) {
    // Reject lines shorter than 10 characters
    if (strlen(line) < 10) return 0;
    
    // Add your custom pattern logic here
    // Example: check if line contains specific pattern
    // The 97% rejection rate comes from this function
    
    return 1;
}

int main() {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned long total = 0;
    unsigned long accepted = 0;

    // Read from stdin line by line
    while ((read = getline(&line, &len, stdin)) != -1) {
        total++;
        if (is_ripe(line)) {
            // Write accepted lines to stdout
            fwrite(line, 1, read, stdout);
            accepted++;
        }
    }
    
    // Print statistics to stderr (not captured by pipe)
    fprintf(stderr, "Total: %lu | Accepted: %lu | Rejected: %.2f%%\n",
            total, accepted, (1 - (double)accepted / total) * 100);
    
    free(line);
    return 0;
}
