fun main(args: Array<String>) {
    val chunks = "__BXCXAXAYBYCYCZAZBZ".chunked(2)
    args
        .asSequence()
        .map { it.replace(" ", "") }
        .fold(0) { points, advice -> points + chunks.indexOf(advice) }
        .let(::println)
}