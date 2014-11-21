/*
 * Copyright (C) 2005, 2006, 2008 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#ifndef MergeIdenticalElementsCommand_h
#define MergeIdenticalElementsCommand_h

#include "EditCommand.h"

namespace WebCore {

class MergeIdenticalElementsCommand : public SimpleEditCommand {
public:
    static PassRefPtr<MergeIdenticalElementsCommand> create(PassRefPtr<Element> element1, PassRefPtr<Element> element2)
    {
        return adoptRef(new MergeIdenticalElementsCommand(element1, element2));
    }

private:
    MergeIdenticalElementsCommand(PassRefPtr<Element>, PassRefPtr<Element>);

    virtual void doApply() override;
    virtual void doUnapply() override;
    
#ifndef NDEBUG
    virtual void getNodesInCommand(HashSet<Node*>&) override;
#endif
    
    RefPtr<Element> m_element1;
    RefPtr<Element> m_element2;
    RefPtr<Node> m_atChild;
};

} // namespace WebCore

#endif // MergeIdenticalElementsCommand_h