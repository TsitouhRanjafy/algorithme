import { tableET, tableOU, tableNON, tableIMPLIQUE } from "./binary_CLI_lib";

const args = process.argv

const arg1: string = args[2]
const operateur: string = args[3]
const arg2: string = args[4]


switch (operateur) {
    case 'ET':
        console.log(tableET(arg1,arg2));
        break;
    case 'OU':
        console.log(tableOU(arg1,arg2));
        break;
    case 'NON':
        console.log(tableNON(arg1));
        break;
    case 'IMPLIQUE':
        console.log(tableIMPLIQUE(arg1,arg2));
        break;
    default:
        console.log(`excepted operator: OU, ET, NON, IMPLIQUE`);
        break;
}