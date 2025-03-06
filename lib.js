export default class Dictionnaire {
    map = new Map();
    set = new Set();
    addValue(key, value) {
        this.map.set(key, value);
        this.set.add(value);
    }
    hasValue(value) {
        return (this.set.has(value)) ? true : false;
    }
    hasKey(key) {
        return (this.map.has(key)) ? true : false;
    }
    getValue(key) {
        return this.map.get(key);
    }
}
