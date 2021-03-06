/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef INCLUDED_SVX_SOURCE_SIDEBAR_GLOW_GLOWPROPERTYPANEL_HXX
#define INCLUDED_SVX_SOURCE_SIDEBAR_GLOW_GLOWPROPERTYPANEL_HXX

#include <vcl/vclptr.hxx>
#include <sfx2/sidebar/ControllerItem.hxx>
#include <svx/sidebar/PanelLayout.hxx>

class ColorListBox;

namespace svx::sidebar
{
class GlowPropertyPanel : public PanelLayout,
                          public ::sfx2::sidebar::ControllerItem::ItemUpdateReceiverInterface
{
public:
    GlowPropertyPanel(vcl::Window* pParent, const css::uno::Reference<css::frame::XFrame>& rxFrame,
                      SfxBindings* pBindings);
    virtual ~GlowPropertyPanel() override;
    virtual void dispose() override;

    static VclPtr<vcl::Window> Create(vcl::Window* pParent,
                                      const css::uno::Reference<css::frame::XFrame>& rxFrame,
                                      SfxBindings* pBindings);

    virtual void NotifyItemUpdate(const sal_uInt16 nSId, const SfxItemState eState,
                                  const SfxPoolItem* pState) override;

private:
    sfx2::sidebar::ControllerItem maGlowController;
    sfx2::sidebar::ControllerItem maGlowColorController;
    sfx2::sidebar::ControllerItem maGlowRadiusController;

    SfxBindings* mpBindings;

    std::unique_ptr<weld::CheckButton> mxShowGlow;
    std::unique_ptr<weld::MetricSpinButton> mxGlowRadius;
    std::unique_ptr<ColorListBox> mxLBGlowColor;
    std::unique_ptr<weld::Label> mxFTRadius;
    std::unique_ptr<weld::Label> mxFTColor;

    void Initialize();
    void UpdateControls();

    DECL_LINK(ClickGlowHdl, weld::ToggleButton&, void);
    DECL_LINK(ModifyGlowColorHdl, ColorListBox&, void);
    DECL_LINK(ModifyGlowRadiusHdl, weld::MetricSpinButton&, void);
};
}

#endif

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
