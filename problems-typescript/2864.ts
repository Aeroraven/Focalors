function maximumOddBinaryNumber(s: string): string {
    let sb = ""
    let n1 = 0, n0 = 0;
    for (let x of s) {
        if (x == '1') n1++;
        else n0++;
    }
    for (let i = 0; i < n1 - 1; i++)sb += '1';
    for (let i = 0; i < n0; i++) sb += '0';
    sb += '1';
    return sb;
};