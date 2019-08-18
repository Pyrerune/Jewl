package io.github.pyrerune;
import io.github.pyrerune.errors.Error;

import java.util.ArrayList;
import java.util.Arrays;

public class Interpreter {
    public Error format(String[] tok) {
        char[] token;
        boolean variable = false;
        ArrayList<String> variables = new ArrayList<String>();
        int lines = 1;
        char[] expr = {'+', '-', '/', '*'};
        for(int i = 0; i < tok.length; i++) {
            switch(tok[i]) {
                case "print":
                    String word = tok[i+1].toString();
                    String variableName = "";
                    token = word.toCharArray();
                    if(token[token.length - 1] != ';') {
                        return new Error(1, "Expected Semicolon at end of line");
                    }
                    token = Arrays.copyOfRange(token, 0, token.length-1);
                    if(token[0] == '"' && token[token.length-1] != '"') {
                        return new Error(1, "Expected Double Quote at end of Print Statement");
                    }
                    if(token[0] != '"') {
                        if(Character.isDigit(token[0])) {
                            if(token.length >= 2 && Character.isDigit(token[1])) {
                                if(token.length >= 3 && charContains(expr, token[2]) < 10) {
                                    int val = charContains(expr, token[2]);
                                    switch(val) {
                                        case 0:
                                            if(token.length >= 4 && Character.isDigit(token[3])) {
                                                if(token.length >= 5 && Character.isDigit(token[4])) {
                                                    int num = Character.getNumericValue(token[0]) * 10 + Character.getNumericValue(token[1]);
                                                    num = num + Character.getNumericValue(token[3]) * 10 + Character.getNumericValue(token[4]);
                                                    word = Integer.toString(num);
                                                } else {
                                                    int num = Character.getNumericValue(token[0]) * 10 + Character.getNumericValue(token[1]);
                                                    num = num + Character.getNumericValue(token[3]);
                                                    word = Integer.toString(num);
                                                }
                                            }
                                    }
                                } else {
                                    int num = Character.getNumericValue(token[0]) * 10 + Character.getNumericValue(token[1]);
                                    word = Integer.toString(num);
                                }
                            } else {
                                if(token.length >= 2 && charContains(expr, token[1]) < 10) {
                                    int val = charContains(expr, token[1]);
                                    switch(val) {
                                        case 0:
                                            if(token.length >= 3 && Character.isDigit(token[2])) {
                                                if(token.length >= 4 && Character.isDigit(token[3])) {
                                                    int num = Character.getNumericValue(token[0]);
                                                    num = num + Character.getNumericValue(token[2]) * 10 + Character.getNumericValue(token[3]);
                                                    word = Integer.toString(num);
                                                } else {
                                                    int num = Character.getNumericValue(token[0]);
                                                    num = num + Character.getNumericValue(token[2]);
                                                    word = Integer.toString(num);
                                                }
                                            }
                                    }
                                } else {
                                    int num = Character.getNumericValue(token[0]);
                                    word = Integer.toString(num);
                                }
                            }
                        }
                    }
                    else {

                        word = "";
                        for (int x = 0; x < token.length; x++) {

                                if(token[x] == '$' && token[x+1] == '{') {
                                    variable = true;
                                    //token = removeChar(token, x);

                                    for (int y = x+2; token[y] != '}'; y++) {
                                        variableName += token[y];
                                    }
                                    word = search(variables, variableName);
                                    continue;
                                }

                                    if(token[x] == '{' || token[x] == '}' || token[x] == '"') {

                                    } else {
                                        if(variable == false) {
                                            word += token[x];
                                        }
                                    }


                        }

                    }
                    if(word != null) {
                        System.out.println(word);
                    }
                    break;
                case "var":
                    String varContent = "";
                    if(!tok[i + 2].equals("=")) {
                        return new Error(2, "Variables must be initialized at the declaration");

                    }
                    token = tok[i+3].toString().toCharArray();

                    token = Arrays.copyOfRange(token, 0, token.length-1);
                    if(token[0] == '"' && token[token.length-1] != '"') {
                        return new Error(1, "Expected Double Quote at end of Print Statement");
                    } else if(token[0] == '"') {

                        token = Arrays.copyOfRange(token, 1, token.length-1);
                        for(int x = 0; x < token.length; x++) {

                                varContent += token[x];

                        }
                    }
                    //System.out.println(tok[i+1]);

                    variables.add(tok[i+1]);
                    variables.add(varContent);



                case ";":
                    lines++;
            }
        }
        return new Error(0, null);
    }

    private int charContains(char[] arr, char item) {
        for(int i = 0; i < arr.length; i++) {
            if(arr[i] == item) {
                return i;
            }
        }
        return 10;
    }
    private char[] removeChar(char[] arr, int index) {
        if(arr.length >= index+1) {
            char[] newArr = new char[arr.length - 1];
            for(int i = 0, k = 0; i < arr.length; i++) {
                if(i == index) {
                    continue;
                }
                newArr[k++] = arr[i];
            }
            return newArr;
        } else {
            return arr;
        }
    }
    private int stringContains(ArrayList<String> arr, String item) {
        for(int i = 0; i < arr.size(); i++) {
            if(arr.get(i).equals(item)) {
                return i;
            }
        }
        return 10;
    }
    private String search(ArrayList<String> arr, String varName) {
        int index = stringContains(arr, varName);
        if(arr.size() >= index + 2) {

            return arr.get(index+1);

        } else {
            return null;
        }


    }
}
