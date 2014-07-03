//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2008 by Eran Ifrah
// file name            : formatoptions.cpp
//
// -------------------------------------------------------------------------
// A
//              _____           _      _     _ _
//             /  __ \         | |    | |   (_) |
//             | /  \/ ___   __| | ___| |    _| |_ ___
//             | |    / _ \ / _  |/ _ \ |   | | __/ _ )
//             | \__/\ (_) | (_| |  __/ |___| | ||  __/
//              \____/\___/ \__,_|\___\_____/_|\__\___|
//
//                                                  F i l e
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
#include "formatoptions.h"
#include "clClangFormatLocator.h"

FormatOptions::FormatOptions()
    : m_options(AS_DEFAULT | AS_INDENT_USES_TABS)
    , m_engine(kFormatEngineAStyle)
    , m_clangFormatOptions(kClangFormatLLVM)
{
    if ( m_clangFormatExe.IsEmpty() ) {
        clClangFormatLocator locator;
        locator.Locate( m_clangFormatExe );
    }
}

FormatOptions::~FormatOptions()
{
}

void FormatOptions::DeSerialize(Archive &arch)
{
    arch.Read(wxT("m_options"), m_options);
    arch.Read(wxT("m_customFlags"), m_customFlags);
    
    int engine = kFormatEngineAStyle;
    arch.Read("m_engine", engine);
    m_engine = static_cast<FormatterEngine>(engine);
    
    arch.Read("m_clangFormatOptions", m_clangFormatOptions);
    arch.Read("m_clangFormatExe", m_clangFormatExe);
}

void FormatOptions::Serialize(Archive &arch)
{
    arch.Write(wxT("m_options"),            m_options);
    arch.Write(wxT("m_customFlags"),        m_customFlags);
    arch.Write("m_engine", static_cast<int>(m_engine));
    arch.Write("m_clangFormatOptions",      m_clangFormatOptions);
    arch.Write("m_clangFormatExe",          m_clangFormatExe);
}

wxString FormatOptions::AstyleOptionsAsString() const
{
    //by default use tabs as indentation with size 4
    wxString options;

    if (m_options & AS_ANSI) {
        options << wxT(" --style=ansi ");
    }
    if (m_options & AS_GNU) {
        options << wxT(" --style=gnu ");
    }
    if (m_options & AS_KR) {
        options << wxT(" --style=kr ");
    }
    if (m_options & AS_LINUX) {
        options << wxT(" --style=linux ");
    }
    if (m_options & AS_JAVA) {
        options << wxT(" --style=java ");
    }
    if (m_options & AS_BRACKETS_BREAK) {
        options << wxT(" -b ");
    }
    if (m_options & AS_BRACKETS_ATTACH) {
        options << wxT(" -a ");
    }
    if (m_options & AS_BRACKETS_LINUX) {
        options << wxT(" -l ");
    }
    if (m_options & AS_BRACKETS_BREAK_CLOSING) {
        options << wxT(" -y ");
    }
    if (m_options & AS_INDENT_CLASS) {
        options << wxT(" -C ");
    }
    if (m_options & AS_INDENT_SWITCHES) {
        options << wxT(" -S ");
    }
    if (m_options & AS_INDENT_CASE) {
        options << wxT(" -K ");
    }
    if (m_options & AS_INDENT_BLOCKS) {
        options << wxT(" -B ");
    }
    if (m_options & AS_INDENT_NAMESPACES) {
        options << wxT(" -N ");
    }
    if (m_options & AS_INDENT_LABELS) {
        options << wxT(" -L ");
    }
    if (m_options & AS_INDENT_PREPROCESSORS) {
        options << wxT(" -w ");
    }
    if (m_options & AS_MAX_INSTATEMENT_INDENT) {
        options << wxT(" -M ");
    }
    if (m_options & AS_BREAK_BLOCKS) {
        options << wxT(" -f ");
    }
    if (m_options & AS_BREAK_BLOCKS_ALL) {
        options << wxT(" -F ");
    }
    if (m_options & AS_BREAK_ELSEIF) {
        options << wxT(" -e ");
    }
    if (m_options & AS_PAD_OPER) {
        options << wxT(" -p ");
    }
    if (m_options & AS_PAD_PARENTHESIS) {
        options << wxT(" -P ");
    }
    if (m_options & AS_PAD_PARENTHESIS_OUT) {
        options << wxT(" -d ");
    }
    if (m_options & AS_PAD_PARENTHESIS_IN) {
        options << wxT(" -D ");
    }
    if (m_options & AS_ONE_LINE_KEEP_STATEMENT) {
        options << wxT(" -o ");
    }
    if (m_options & AS_ONE_LINE_KEEP_BLOCKS) {
        options << wxT(" -O ");
    }
    if (m_options & AS_FILL_EMPTY_LINES) {
        options << wxT(" -E ");
    }
    if (m_options & AS_UNPAD_PARENTHESIS) {
        options << wxT(" -U ");
    }
    if(m_customFlags.IsEmpty() == false) {
        options << wxT(" ") << m_customFlags;
    }
    return options;
}

wxString FormatOptions::ClangFormatOptionsAsString() const
{
    wxString options;
    if ( m_clangFormatOptions & kClangFormatChromium ) {
        options << " -style=Chromium ";
    } else if ( m_clangFormatOptions & kClangFormatGoogle ) {
        options << " -style=Google ";
    } else if ( m_clangFormatOptions & kClangFormatLLVM ) {
        options << " -style=LLVM ";
    } else if ( m_clangFormatOptions & kClangFormatMozilla ) {
        options << " -style=Mozilla ";
    } else if ( m_clangFormatOptions & kClangFormatWebKit ) {
        options << " -style=WebKit ";
    }
    options << " -i "; // inplace editing
    return options;
}
