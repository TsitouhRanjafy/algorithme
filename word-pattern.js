import Dictionnaire from "./lib";
const wordPattern = (pattern, str) => {
    if (typeof (str) == 'string')
        str = str.split(new RegExp(" ", "g"));
    if (pattern.length != str.length)
        return false;
    let patternDico = new Dictionnaire();
    for (let i = 0; i < pattern.length; i++) {
        if (patternDico.hasKey(pattern[i]) && (patternDico.getValue(pattern[i]) != str[i]))
            return false;
        if (patternDico.hasValue(str[i]) && !patternDico.hasKey(pattern[i]))
            return false;
        patternDico.addValue(pattern[i], str[i]);
    }
    return true;
};
wordPattern('abba', "dog chien chien dog");
