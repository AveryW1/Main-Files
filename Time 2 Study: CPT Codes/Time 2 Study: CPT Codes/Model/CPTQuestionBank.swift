//
//  CPTQuestionBank.swift
//  Time 2 Study: CPT Codes
//
//  Created by Avery Washington on 8/3/18.
//  Copyright © 2018 General Cloud Applications LLC. All rights reserved.
//

import Foundation

class QuestionBank {
    
//The property 'list' creates an array that contains all of the questions listed below.
    var list = [Question]()

//List of questions and the answers. The answers are given in an array that is
    init() {
        list.append(Question(question: "Question 1", answerA: "A", answerB: "B", answerC: "C", answerD: "D", answer: 2))
        list.append(Question(question: "Question 2", answerA: "A2", answerB: "B2", answerC: "C2", answerD: "D2", answer: 1))
        list.append(Question(question: "Question 3", answerA: "A", answerB: "B", answerC: "C", answerD: "D", answer: 3))
        list.append(Question(question: "Question 4", answerA: "A", answerB: "B", answerC: "C", answerD: "D", answer: 4))
        list.append(Question(question: "Question 5", answerA: "A", answerB: "B", answerC: "C", answerD: "D", answer: 2))
        list.append(Question(question: "Question 6", answerA: "A", answerB: "B", answerC: "C", answerD: "D", answer: 2))
        list.append(Question(question: "Question 7", answerA: "A", answerB: "B", answerC: "C", answerD: "D", answer: 2))
        list.append(Question(question: "Question 8", answerA: "A", answerB: "B", answerC: "C", answerD: "D", answer: 2))
        list.append(Question(question: "Question 9", answerA: "A", answerB: "B", answerC: "C", answerD: "D", answer: 2))
        list.append(Question(question: "Question 10", answerA: "A", answerB: "B", answerC: "C", answerD: "D", answer: 2))
        list.append(Question(question: "Question 11", answerA: "A", answerB: "B", answerC: "C", answerD: "D", answer: 2))
        list.append(Question(question: "Question 12", answerA: "A", answerB: "B", answerC: "C", answerD: "D", answer: 2))
        list.append(Question(question: "Question 13", answerA: "A", answerB: "B", answerC: "C", answerD: "D", answer: 2))
       
    }
    
    
}
