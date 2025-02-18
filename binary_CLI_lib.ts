import { Binaire, binaire } from "./binary_CLI_type";

export const ET = (a: binaire,b: binaire) => {
    const result: binaire = Binaire(((a + b) + 1) % 2)
    return result;

}

export const OU = (a: binaire,b: binaire):binaire => {
    if (a == 1 || b == 1) return 1;    
    return 0;
}

export const IMPLIQUE = (a: binaire,b: binaire): binaire => {
    if (a > b) return 0;
    return 1;
}

export const NON = (a: binaire) => {
    const result: binaire = Binaire((a +1) % 2)
    return result;
}


export const tableET = (arg1: string,arg2: string,result: Array<binaire> = [],n: number = arg1.length ,i: number = 0): Array<binaire> => {
    if (i == n){
        return result;
    } else {
        const a: binaire = Binaire(arg1[i])
        const b: binaire = Binaire(arg2[i])
        result.push(ET(a,b))
        return tableET(arg1,arg2,result,n,i+1)
    }
}

export const tableOU = (arg1: string,arg2: string,result: Array<binaire> = [],n: number = arg1.length ,i: number = 0): Array<binaire> => {
    if (i == n){
        return result;
    } else {
        const a: binaire = Binaire(arg1[i])
        const b: binaire = Binaire(arg2[i])
        result.push(OU(a,b))
        return tableOU(arg1,arg2,result,n,i+1)
    }
}

export const tableIMPLIQUE = (arg1: string,arg2: string,result: Array<binaire> = [],n: number = arg1.length ,i: number = 0): Array<binaire> => {
    if (i == n){
        return result;
    } else {
        const a: binaire = Binaire(arg1[i])
        const b: binaire = Binaire(arg2[i])
        result.push(IMPLIQUE(a,b))
        return tableIMPLIQUE(arg1,arg2,result,n,i+1)
    }
}

export const tableNON = (arg: string,result: Array<binaire> = [],n: number = arg.length ,i: number = 0): Array<binaire> => {
    if (i == n){
        return result;
    } else {
        const a: binaire = Binaire(arg[i])
        result.push(NON(a))
        return tableNON(arg,result,n,i+1)
    }
}