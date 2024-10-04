// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "TreeSitterTree",
    products: [
        .library(name: "TreeSitterTree", targets: ["TreeSitterTree"]),
    ],
    dependencies: [
        .package(url: "https://github.com/ChimeHQ/SwiftTreeSitter", from: "0.8.0"),
    ],
    targets: [
        .target(
            name: "TreeSitterTree",
            dependencies: [],
            path: ".",
            sources: [
                "src/parser.c",
                // NOTE: if your language has an external scanner, add it here.
            ],
            resources: [
                .copy("queries")
            ],
            publicHeadersPath: "bindings/swift",
            cSettings: [.headerSearchPath("src")]
        ),
        .testTarget(
            name: "TreeSitterTreeTests",
            dependencies: [
                "SwiftTreeSitter",
                "TreeSitterTree",
            ],
            path: "bindings/swift/TreeSitterTreeTests"
        )
    ],
    cLanguageStandard: .c11
)
