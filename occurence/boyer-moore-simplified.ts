var text: string = 'abracadabradabhddabrdabla';
var pattern: string = 'dab';
var rightPos: Map<string, number> = new Map<string, number>();

console.log(count_occurence(text, pattern));


function count_occurence(text: string, pattern: string): number {
    let i: number = 0;
    let compteur: number = 0;
    while(true){
        let occurence = search(text, pattern, i);
        if (occurence === -1) 
            return compteur
        else {
            compteur++;
            i += occurence;
        }
    }
}

function search(text: string, pattern: string, start: number = 0): number {
    let n = text.length;
    let p = pattern.length;
    let i = start;
    setRightPos(pattern, p);
    while (i + p <= n) {
        let isOk_decalage: Array<boolean | number> = correspondance(text, pattern, p, i);
        let isok: boolean = Boolean(isOk_decalage[0]);
        let decalage: number = parseInt(isOk_decalage[1]+"");

        if (isok)
            return i;
        else
            i += decalage; 
    }
    return -1
}

function correspondance(text: string, pattern: string, p: number, i: number): Array<boolean | number> {
    let x: string;
    let decalage: number;
    for (let j = p - 1; j >= 0; j--) {
        x = text[i + j];
        if (x != pattern[j]) {
            decalage = Math.max(1, j - right(x))
            return [false, decalage]
        }
    }
    return [true, 0]
}

function setRightPos(pattern: string, p: number = pattern.length) {
    for (let j: number = 0; j < p; j++) {
        rightPos.set(pattern[j], j)
    }
}

function right(char: string): number {
    let pos: number | undefined = rightPos.get(char);
    if ( pos != undefined )
        return pos;
    else
        return -1
}


/*

function boyer_moore_simplified(text: string, pattern: string, start: number = 0): Array<number> {
    let i= start;
    while (i < n) {
        let j = p - 1;
        if (pattern[j] != text[i + j]) {
            i += calculOffset(text, pattern, i, j);
        } else {
            j--;
            let isBreaked = false;
            while (j >= 0) {
                if (pattern[j] != text[i + j]) {
                    i += calculOffset(text, pattern, i, j);
                    console.log();
                    
                    isBreaked = true;
                    break;
                }
                j--;
            }
            if (j === -1) return [i, i + p - 1];
            if (!isBreaked) i++;
        }
    }
    return [-1, -1];
}

function calculOffset(text: string, pattern: string, i: number, j: number): number { 
    let x = i + j;
    let pos_x_in_pattern: number | undefined = rightPos.get(text[x]);
    if (!pos_x_in_pattern) return 1 + j;
    if (j < p - 1 - pos_x_in_pattern) return p;
    return (j - (p - 1 - pos_x_in_pattern));
}

function rightPosInMap(text: string): Map<string, number> {
    let rightPos: Map<string, number> = new Map<string, number>();
    for (let i = 0; i < text.length; i++) {
        rightPos.set(text[i], text.length - i - 1);
    }
    return rightPos;
}


let occurence = boyer_moore_simplified(text, pattern);
console.log(occurence);

*/


