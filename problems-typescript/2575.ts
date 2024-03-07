function divisibilityArray(word: string, m: number): number[] {
    let ret = []
    let accu = 0
    for (let i = 0; i < word.length; i++) {
        accu *= 10
        accu += parseInt(word.charAt(i))
        accu %= m
        if (accu == 0) {
            ret.push(1)
        } else {
            ret.push(0)
        }
    }
    return ret
};