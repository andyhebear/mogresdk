namespace Mogre.Demo.MogreForm
{
    partial class MogreForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.mogrePanel = new System.Windows.Forms.Panel();
            this.SuspendLayout();
            // 
            // mogrePanel
            // 
            this.mogrePanel.Location = new System.Drawing.Point(150, 68);
            this.mogrePanel.Name = "mogrePanel";
            this.mogrePanel.Size = new System.Drawing.Size(483, 375);
            this.mogrePanel.TabIndex = 0;
            // 
            // MogreForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(810, 544);
            this.Controls.Add(this.mogrePanel);
            this.Name = "MogreForm";
            this.Text = "Simple Mogre Form";
            this.Paint += new System.Windows.Forms.PaintEventHandler(this.MogreForm_Paint);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel mogrePanel;

    }
}

