//
//  Questions.swift
//  Time 2 Study: CPT Codes
//
//  Created by Avery Washington on 8/3/18.
//  Copyright © 2018 General Cloud Applications LLC. All rights reserved.
//

import Foundation


/*This is the model for questions. Questions will contain text and 4 possible answers. Answers will be strings instead of tags to allow them to change with each question instead of being linked to a button as one would do for a true/false quiz.
*/

 class Question {
    let questionText : String
    let optionA : String
    let optionB : String
    let optionC : String
    let optionD : String
    let correctAnswer : Int
    
/*Initialization is the assignment of an initial value for a data object or variable. Classes must be initialized. The declariation of constants/properties above is to let the program know these exist and what data type they are. Then these are linked to the parameters that you list below in the initialization. After this 'object' is created, you can call it in other places in your program and it will show you the auto complete popup to fill out.
*/
    
    init(question: String, answerA: String, answerB: String, answerC: String, answerD: String, answer: Int) {
        questionText = question
        optionA = answerA
        optionB = answerB
        optionC = answerC
        optionD = answerD
        correctAnswer = answer
    }
}
