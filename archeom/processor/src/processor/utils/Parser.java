package processor.utils;

import processor.misc.Instruction;
import processor.misc.Instructions;
import processor.misc.operands.Operand;
import processor.misc.operands.Operands;

import java.util.ArrayList;

/**
 * Created by lionell on 24.02.16.
 *
 * @author Ruslan Sakevych
 */
public class Parser {
    public static Instruction[] process(ArrayList<String[]> lexemes) {
        Instruction[] instructions = new Instruction[lexemes.size()];
        for (int i = 0; i < lexemes.size(); i++) {
            String[] command = lexemes.get(i);
            Operand[] operands = new Operand[command.length - 1];
            for (int j = 1; j < command.length; j++) {
                if (command[j].charAt(0) == 'R' || command[j].charAt(0) == 'r') {
                    operands[j - 1] = new Operand(Operands.Address, Integer.parseInt(command[j].substring(1)));
                } else {
                    operands[j - 1] = new Operand(Operands.Number, Integer.parseInt(command[j]));
                }
            }
            instructions[i] = new Instruction(Instructions.valueOf(command[0].toUpperCase()), operands);
        }
        return instructions;
    }
}
