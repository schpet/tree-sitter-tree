import XCTest
import SwiftTreeSitter
import TreeSitterTree

final class TreeSitterTreeTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_tree())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading Tree grammar")
    }
}
