#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp = fopen("orig.txt", "r");
    FILE *output = fopen("output.txt", "w");
    if (!fp) {
        printf("ERROR opening input file orig.txt\n");
        exit(0);
    }
    int i = 0;
    char append[50], find[50];
    double orig_sum_a = 0.0, orig_sum_f = 0.0, orig_a, orig_f;
    for (i = 0; i < 100; i++) {
        if (feof(fp)) {
            printf("ERROR: You need 100 datum instead of %d\n", i);
            printf("run 'make run' longer to get enough information\n\n");
            exit(0);
        }
        fscanf(fp, "%s %s %lf %lf\n", append, find, &orig_a, &orig_f);
        orig_sum_a += orig_a;
        orig_sum_f += orig_f;
    }
    fclose(fp);

    fp = fopen("opt.txt", "r");
    if (!fp) {
        fp = fopen("orig.txt", "r");
        if (!fp) {
            printf("ERROR opening input file opt.txt\n");
            exit(0);
        }
    }
    double opt_sum_a = 0.0, opt_sum_f = 0.0, opt_a, opt_f;
    for (i = 0; i < 100; i++) {
        if (feof(fp)) {
            printf("ERROR: You need 100 datum instead of %d\n", i);
            printf("run 'make run' longer to get enough information\n\n");
            exit(0);
        }
        fscanf(fp, "%s %s %lf %lf\n", append, find, &opt_a, &opt_f);
        opt_sum_a += opt_a;
        opt_sum_f += opt_f;
    }

    FILE *fp_bst = fopen("bst.txt", "r");
    if (!fp_bst) {
        printf("ERROR opening input file bst.txt\n");
        exit(0);
    }
    double bst_sum_a = 0.0, bst_sum_f = 0.0, bst_a, bst_f;
    for (i = 0; i < 10; i++) {
        if (feof(fp_bst)) {
            printf("ERROR: You need 10 datum instead of %d\n", i);
            printf("run 'make run' longer to get enough information\n\n");
            exit(0);
        }
        fscanf(fp_bst, "%s %s %lf %lf\n", append, find, &bst_a, &bst_f);
        bst_sum_a += bst_a;
        bst_sum_f += bst_f;
    }
    fclose(fp_bst);
    FILE *fp_huf = fopen("huf.txt", "r");
    if (!fp_huf) {
        printf("ERROR opening input file huf.txt\n");
        exit(0);
    }
    double huf_sum_a = 0.0, huf_sum_f = 0.0, huf_a, huf_f;
    for (i = 0; i < 20; i++) {
        if (feof(fp_huf)) {
            printf("ERROR: You need 10 datum instead of %d\n", i);
            printf("run 'make run' longer to get enough information\n\n");
            exit(0);
        }
        fscanf(fp_bst, "%s %s %lf %lf\n", append, find, &huf_a, &huf_f);
        huf_sum_a += huf_a;
        huf_sum_f += huf_f;
    }
    fclose(fp_huf);
    fprintf(output, "append() %lf %lf %lf %lf\n",0.061372, opt_sum_a / 100.0, bst_sum_a / 10.0, huf_sum_a / 20.0);
    fprintf(output, "findName() %lf %lf %lf %lf", orig_sum_f / 100.0, opt_sum_f / 100.0, bst_sum_f / 10.0,huf_sum_f / 20.0);
    fclose(output);
    fclose(fp);
    

    return 0;
}
