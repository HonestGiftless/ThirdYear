package com.example.guessthenumber

import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity

class GameActivity : AppCompatActivity(){
    var firstNum: Int = 0
    var secondNum: Int = 100
    var abs: Int = 0

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_game)

        val question = findViewById<TextView>(R.id.isUrNum)

        firstNum = intent.getIntExtra("firstNum", 0)
        secondNum = intent.getIntExtra("secondNum", 100)
        Log.d("mytag", "firstNum = " + firstNum)
        Log.d("mytag", "secondNum = " + secondNum)

        abs = (firstNum + secondNum) / 2
        "Your number is less than $abs?".also { question.text = it }

        fun choseYesOrNo(view: View) {
            when (view.id) {
                R.id.btnYes -> {
                    secondNum = abs
                    abs = (firstNum + secondNum) / 2
                    question.text = "Your number is less than $abs?"
                }

                R.id.btnNo -> {
                    firstNum = abs
                    abs = (firstNum + secondNum) / 2
                    question.text = "Your number is less than $abs?"
                }
            }
            if (secondNum - 1 == firstNum) {
                question.text = "Your number is $firstNum"
            }
        }
    }
}