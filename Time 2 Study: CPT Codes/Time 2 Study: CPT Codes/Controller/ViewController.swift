//
//  ViewController.swift
//  Time 2 Study: CPT Codes
//
//  Created by Avery Washington on 8/3/18.
//  Copyright © 2018 General Cloud Applications LLC. All rights reserved.
//

//This app still needs questions, graphics (icons), and contraints for all screen sizes.

import UIKit

class ViewController: UIViewController {

    let allQuestions = QuestionBank()
    var chosenAnswer : Int = 0
    var questionNumber : Int = 0
    var score: Int = 0
    var selectedAnser: Int = 0
    
    @IBOutlet weak var scoreLabel: UILabel!
    @IBOutlet weak var progressLabel: UILabel!
    @IBOutlet weak var progressBar: UIView!
    @IBOutlet weak var questionDisplay: UILabel!
    
    //Outlets had to be created for each button to allow the answers (text displayed) change with each question.
    
    @IBOutlet weak var answerA: UIButton!
    @IBOutlet weak var answerB: UIButton!
    @IBOutlet weak var answerC: UIButton!
    @IBOutlet weak var answerD: UIButton!
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Do any additional setup after loading the view, typically from a nib. 343 217
        
        nextQuestion()
        
    }
    
    
    //This action allows for the selection of multiple choice questions.
    
    @IBAction func answerSelected(_ sender: UIButton) {
        if sender.tag == 1{
            print("option a")
            chosenAnswer = 1
        }
        else if sender.tag == 2{
            print("option b")
            chosenAnswer = 2
        }
        else if sender.tag == 3{
            print("option c")
            chosenAnswer = 3
        }
        else {
            print("option d")
            chosenAnswer = 4
        }
        
        checkAnswer()
        questionNumber += 1
        nextQuestion()
        
    }
    
//This fucntion will update the UI to show an updated score and progress bar.
    
    func updateUI() {
        
        scoreLabel.text = "\(score)"
        progressLabel.text = "\(questionNumber + 1) /13"
        progressBar.frame.size.width = (view.frame.size.width / 13) * CGFloat(questionNumber + 1)
    }
    
/*This function progresses to the next question after an answer is chosen. If all questions are done
then an alert will be triggered to request restarting.*/
    
    func nextQuestion() {
        
        if questionNumber <= 12{
            questionDisplay.text = allQuestions.list[questionNumber].questionText
            answerA.setTitle(allQuestions.list[questionNumber].optionA, for: UIControlState.normal)
            answerB.setTitle(allQuestions.list[questionNumber].optionB, for: UIControlState.normal)
            answerC.setTitle(allQuestions.list[questionNumber].optionC, for: UIControlState.normal)
            answerD.setTitle(allQuestions.list[questionNumber].optionD, for: UIControlState.normal)
            updateUI()
            scoreLabel.text = "Score: \(score)"
        }
        else {
            
            let alert = UIAlertController(title: "End of Quiz", message: "Would you like to restart?", preferredStyle: .alert)
            
            let restartAction = UIAlertAction(title: "Restart", style: .default, handler: { (UIAlertAction) in
                self.restartQuiz()
            })
            
            alert.addAction(restartAction)
            present(alert, animated: true, completion: nil)
            
        }
        
    }
    
//This function is used to check if the answer matches the correct one from the bank.
    
    func checkAnswer() {
        let rightAnswer = allQuestions.list[questionNumber].correctAnswer
        if rightAnswer == chosenAnswer {
            
            ProgressHUD.showSuccess("Correct!")
            score += 1
            
        }
        else {
            
            ProgressHUD.showError("Sorry, wrong.")
            
        }
    }
    
//This function resets the question number, score, and progress.
    
    func restartQuiz() {
        
        questionNumber = 0
        nextQuestion()
        score = 0
        
    }

}

