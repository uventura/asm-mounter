//=====================================================================================================
//    CODE COMES FROM: https://doc.qt.io/qt-6/qtwidgets-richtext-syntaxhighlighter-example.html
//=====================================================================================================

#ifndef HIGHLIGHTER_H
#define HIGHLIGHTER_H

#include <QString>
#include <QColor>
#include <QSyntaxHighlighter>
#include <QRegularExpression>
#include <QTextCharFormat>
#include <QList>

class Highlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    Highlighter(QTextDocument *parent = nullptr);

    void addSpecialWord(QString word);
    void clearWords();

protected:
    void highlightBlock(const QString &text) override;

private:
    struct HighlightingRule
    {
        QRegularExpression pattern;
        QTextCharFormat format;
    };

    QList<HighlightingRule> highlightingRules;
    QList<HighlightingRule> specialWords;

    QRegularExpression commentStartExpression;
    QRegularExpression commentEndExpression;

    QTextCharFormat keywordFormat;
    QTextCharFormat classFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat functionFormat;
};

#endif // HIGHLIGHTER_H
