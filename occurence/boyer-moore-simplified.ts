let text: string = 'abracadabra';
let pattern: string = 'dab'; // position 6 - 8 in text
let n: number = text.length;
let p: number = pattern.length;


function searchOccurence(text: string, pattern: string) {
    let i= 0;
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
    let pos_x_in_pattern = searchRightPos(pattern, text[x], p - 1 - j);
    if (pos_x_in_pattern == -1) return p;
    if (j < p - 1 - pos_x_in_pattern) return p;
    return Math.abs(p - 1 - pos_x_in_pattern + j);
}

// console.log(calculOffset("ahcamam", "maam", 3, 3));


function rightPosInMap(text: string): Map<string, number> {
    let rightPos: Map<string, number> = new Map<string, number>();
    for (let i = 0; i < text.length; i++) {
        // console.log(text[i], ":", text.length - i - 1);
        rightPos.set(text[i], text.length - i - 1);
    }
    return rightPos;
}

// console.log(rightPosInMap("maman"));


/**
 * return -1 if not found
 * case-sensitive, space-sensitive
 */
function searchRightPos(text: string, char: string, start: number): number {
    for (let i = text.length - 1 - start; i >= 0; i--)
        if (text[i] === char) return (text.length - i - 1)
    return -1;
}


let occurence = searchOccurence(text, pattern);
console.log(occurence);



