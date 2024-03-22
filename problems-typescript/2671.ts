class FrequencyTracker {
    public freq: Uint32Array;
    public counter: Map<number, number>

    constructor() {
        this.freq = new Uint32Array(100001);
        this.counter = new Map<number, number>();
    }

    add(number: number): void {
        if (this.counter.has(number) == false) {
            this.counter.set(number, 0)
        }
        this.freq[this.counter.get(number)]--;
        this.counter.set(number, this.counter.get(number) + 1);
        this.freq[this.counter.get(number)]++;

    }

    deleteOne(number: number): void {
        if (this.counter.has(number) == false) {
            this.counter.set(number, 0)
        }
        if (this.counter.get(number) == 0) return;
        this.freq[this.counter.get(number)]--;
        this.counter.set(number, this.counter.get(number) - 1);
        this.freq[this.counter.get(number)]++;
    }

    hasFrequency(frequency: number): boolean {
        return this.freq[frequency] >= 1;
    }
}