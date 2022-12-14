import java.util.*

enum class Direction {
    UP, LEFT, DOWN, RIGHT
}

data class Robot(private var x: Int, private var y: Int, private var direction: Direction) {

    fun getDirection(): Direction {
        return direction
    }

    fun getX(): Int {
        return x
    }

    fun getY(): Int {
        return y
    }

    fun turnLeft() {
        when (direction) {
            Direction.UP -> direction = Direction.LEFT
            Direction.LEFT -> direction = Direction.DOWN
            Direction.DOWN -> direction = Direction.RIGHT
            Direction.RIGHT -> direction = Direction.UP
        }
    }

    fun turnRight() {
        when (direction) {
            Direction.UP -> direction = Direction.RIGHT
            Direction.LEFT -> direction = Direction.DOWN
            Direction.DOWN -> direction = Direction.LEFT
            Direction.RIGHT -> direction = Direction.UP
        }
    }

    fun stepForward() {
        when (direction) {
            Direction.UP -> y += 1
            Direction.DOWN -> y -= 1
            Direction.LEFT -> x -= 1
            Direction.RIGHT -> x += 1
        }
    }

    override fun toString(): String {
        return "x: $x, y: $y, dir: $direction"
    }

    fun moveTo(i: Int, i1: Int) {

    }
}

fun moveRobot(x1: Int, y1: Int, robot: Robot) {
    val x = robot.getX()
    val dx = x1 - x
    when (dx > 0) {
        true -> {
            while (robot.getDirection() != Direction.RIGHT) robot.turnRight()
            while (robot.getX() < x1) {
                robot.stepForward()
                println(robot.toString())
            }
        }
        false -> {
            while (robot.getDirection() != Direction.LEFT) robot.turnLeft()
            while (robot.getX() > x1) {
                robot.stepForward()
                println(robot.toString())
            }
        }
    }
    val y = robot.getY()
    val dy = y1 - y
    when (dy > 0) {
        true -> {
            while (robot.getDirection() != Direction.UP) robot.turnRight()
            while (robot.getY() < y1) {
                robot.stepForward()
                println(robot.toString())
            }
        }
        false -> {
            while (robot.getDirection() != Direction.DOWN) robot.turnLeft()
            while (robot.getY() > y1){
                robot.stepForward()
                println(robot.toString())
            }
        }
    }
    println(robot.toString())
}

fun main(args: Array<String>) {
    val r = Robot(1, 1, Direction.RIGHT)
    r.stepForward()

    println(r)
}
