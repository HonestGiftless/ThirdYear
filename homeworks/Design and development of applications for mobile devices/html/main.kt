import java.io.PrintWriter

data class Message(val address: String?, val topic: String?) {

}

fun main() {
    fun Message.toHTML(): String {
        var template = "<html> \n  <table> \n    <style> html{background-color:#FFFAFA; font-size: 100%; font-family: Roboto; color: #008080;}</style> \n"
        address?.let {template += "    <tr><td>address</td><td>$it</td></tr> \n" }
        topic?.let { template +="    <tr><td>address</td><td>$it</td></tr> \n" }
        template += "  </table> \n</html> \n"
        return template
    }

    val m = Message("askbill@microsoft.com", null)
    val writer = PrintWriter("mail.html")
    writer.append(m.toHTML())
    writer.close()
}
