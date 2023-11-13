/*
** EPITECH PROJECT, 2023
** MY_GETNBR
** File description:
** Returns a number, sent to the function as a string
*/
static int validate(char c, char *nbr, int *len)
{
    if ((c >= '0' && c <= '9') || c == '-' || c == '+') {
        nbr[*len] = c;
        *len += 1;
        return 1;
    }
    return 0;
}

static int transform(char *nbr, int len, int neg, int pos)
{
    long int result = 0;

    for (int i = pos; i < len; i++) {
        result = result * 10;
        result += (nbr[i] - '0');
        if ((neg == 1 && result > 2147483647)
            || (neg == -1 && result > 2147483648)) {
            return 0;
        }
    }
    if (neg == -1 && nbr[0] != '0') {
        result = result * -1;
    }
    return result;
}

static int set_found(int valid, int found)
{
    if (valid == 1) {
        if (found == 0) {
            return 1;
        }
        return 2;
    } else if (valid == 0) {
        return 3;
    }
    return 0;
}

static int set_neg(char const *str, int *pos)
{
    int cur = 1;

    while (str[*pos] != '\0') {
        if (str[*pos] >= '0' && str[*pos] <= '9')
            break;
        if (str[*pos] == '-') {
            cur *= -1;
        }
        *pos = *pos + 1;
    }
    return cur;
}

int my_getnbr(char const *str)
{
    char c;
    char nbr[20];
    int i = 0;
    int len = 0;
    int neg = 1;
    int pos = 0;
    int valid;

    do {
        c = str[i];
        valid = validate(c, nbr, &len);
        i ++;
    } while (c != '\0' && valid != 0);
    nbr[len] = '\0';
    neg = set_neg(nbr, &pos);
    return transform(nbr, len, neg, pos);
}
