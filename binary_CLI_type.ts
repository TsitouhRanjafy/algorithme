import { error } from "console";

export type binaire = 1 | 0;

export const Binaire = (a: string | number ): binaire => {
    const b = Number(a)
    if (b == 1 || b == 0){
        return b
    }
    throw new Error('Error to convert a binaire')
}