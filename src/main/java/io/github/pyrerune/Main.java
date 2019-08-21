package io.github.pyrerune;

import io.github.pyrerune.errors.Error;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Interpreter interpreter = new Interpreter();
            Scanner file = null;
            try {
                file = new Scanner(new File(args[0]));

                String contents = "";
                String[] tok;
                while(file.hasNext()) {
                    contents += file.next() + " ";
                }
                tok = contents.split(" ");
                interpreter.format(tok);
                file.close();
            } catch (FileNotFoundException e) {
                System.out.println("Jewl Intepreter\nVersion: 5.0.2-1");
            }


        //checkError(error);
    }
    private static void checkError(Error error) {
        int errorCode = error.getErrorCode();
        String errorMessage = error.getErrorMessage();
        switch(errorCode) {
            case 1:
                System.out.println("SyntaxError: " + errorMessage);
            case 2:
                System.out.println("UninitializedVariableError: " + errorMessage);
            default:
                return;
        }
    }
}
