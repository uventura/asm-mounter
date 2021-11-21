#include "highlighter.h"

Highlighter::Highlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{

    HighlightingRule rule;

    // Special Default Word - Used For other Languages
    addSpecialWord("if");
    addSpecialWord("else");
    addSpecialWord("elif");
    addSpecialWord("while");
    addSpecialWord("for");

    addSpecialWord("void");
    addSpecialWord("int");
    addSpecialWord("float");
    addSpecialWord("double");
    addSpecialWord("string");
    addSpecialWord("bool");
    addSpecialWord("class");

    addSpecialWord("auto");
    addSpecialWord("nullptr");
    addSpecialWord("vector");
    addSpecialWord("using");
    addSpecialWord("namespace");
    addSpecialWord("#include");

    addSpecialWord("def", Qt::gray);


    /*
    // QT Expressions
    classFormat.setFontWeight(QFont::Bold);
    classFormat.setForeground(Qt::darkMagenta);
    rule.pattern = QRegularExpression(QStringLiteral("\\bQ[A-Za-z]+\\b"));
    rule.format = classFormat;
    highlightingRules.append(rule);*/

    // Between Double Cotes
    quotationFormat.setForeground(Qt::darkCyan);
    rule.pattern = QRegularExpression(QStringLiteral("\".*\""));
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    // Between Single Cotes
    rule.pattern = QRegularExpression(QStringLiteral("'.*'"));
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    // Function Highlight
    functionFormat.setForeground(Qt::yellow);
    rule.pattern = QRegularExpression(QStringLiteral("\\b[A-Za-z0-9_]+(?=\\()"));
    rule.format = functionFormat;
    highlightingRules.append(rule);

    // Label Highlight
    functionFormat.setForeground(Qt::magenta);
    rule.pattern = QRegularExpression(QStringLiteral("\\b[A-Za-z0-9_]+:"));
    rule.format = functionFormat;
    highlightingRules.append(rule);

    // C++ Single Line Comment
    singleLineCommentFormat.setForeground(Qt::darkGray);
    rule.pattern = QRegularExpression(QStringLiteral("//[^\n]*"));
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    // Python Single Line Comment
    singleLineCommentFormat.setForeground(Qt::darkGray);
    rule.pattern = QRegularExpression(QStringLiteral("#[^\n]*"));
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    // C++ Multiple Lines Comment
    multiLineCommentFormat.setForeground(Qt::darkGray);

    commentStartExpression = QRegularExpression(QStringLiteral("/\\*"));
    commentEndExpression = QRegularExpression(QStringLiteral("\\*/"));

    // Python Multiple Lines Comment
    quotationFormat.setForeground(Qt::gray);
    rule.pattern = QRegularExpression(QStringLiteral("'''*'''"));
    rule.format = quotationFormat;
    highlightingRules.append(rule);
}

void Highlighter::addSpecialWord(QString word, QColor color)
{
    HighlightingRule rule;

    QBrush specialColor(Qt::SolidPattern);
    specialColor.setColor(color);

    keywordFormat.setForeground(specialColor);
    keywordFormat.setFontWeight(QFont::Bold);

    rule.pattern = QRegularExpression("\\b"+word+"\\b");
    rule.format = keywordFormat;

    specialWords.append(rule);
}

void Highlighter::clearWords()
{
    specialWords.clear();
}

void Highlighter::highlightBlock(const QString &text)
{
    for (const HighlightingRule &rule : qAsConst(highlightingRules))
    {
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext())
        {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }

    for (const HighlightingRule &rule : qAsConst(specialWords))
    {
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext())
        {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }

    setCurrentBlockState(0);
    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = text.indexOf(commentStartExpression);

    while (startIndex >= 0)
    {
        QRegularExpressionMatch match = commentEndExpression.match(text, startIndex);
        int endIndex = match.capturedStart();
        int commentLength = 0;
        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex
                            + match.capturedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = text.indexOf(commentStartExpression, startIndex + commentLength);
    }
}
